#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


class FileBuffer
{
	public:
		FileBuffer(std::ifstream & file)
			: m_bufLen(0),
			m_curInBuf(m_buf),
			m_file(file),
			m_isLastElementTag(false)
		{
			m_buf[0] = 0;
		}

		~FileBuffer()
		{
			if(m_file) {
				m_file.close();
			}
		}

		std::string nextElement();
		std::string outputBuf();
	private:
		char * findTagHead();
		char * findTagEnd();
		std::string findTag();
		bool readMore();
	private:
		static const size_t MAX_BUF_LEN = 4 * 1024;
		char m_buf[MAX_BUF_LEN + 1];
		size_t m_bufLen;
		char * m_curInBuf;
		std::ifstream & m_file;

		bool m_isLastElementTag;
		std::string m_curTag;
};

char* FileBuffer::findTagHead()
{
	char * pos = strchr(m_curInBuf, '<');
	if (pos) {
		m_curInBuf = pos + 1;
	}
	return pos;
}

char * FileBuffer::findTagEnd()
{
	char * pos = strchr(m_curInBuf, '>');
	if (pos) {
		m_curInBuf = pos + 1;
	}
	return pos;
}

std::string FileBuffer::findTag()
{
	std::string tag;

	char * tagHead = findTagHead();
	while(!tagHead && readMore()) {
		tagHead = findTagHead();
	}

	if (tagHead) {
		char * tagEnd = findTagEnd();
		if (tagEnd) {
			tag.append(tagHead, tagEnd + 1 - tagHead);
			return tag;
		} else {
			tag.append(tagHead);
		}

		while(readMore() && !(tagEnd = findTagEnd())) {
			tag.append(m_buf);
		}
		if (tagEnd) {
			tag.append(m_buf, tagEnd - m_buf + 1);
		}
	}

	return tag;
}

bool FileBuffer::readMore()
{
	if (m_file) {
		m_file.read(m_buf, MAX_BUF_LEN);

		if (m_file) {
			m_bufLen = MAX_BUF_LEN;
			m_buf[MAX_BUF_LEN] = 0;
		} else {
			m_bufLen = m_file.gcount();
			m_buf[m_bufLen] = 0;
			std::cout << "read failed. " << m_bufLen << std::endl;
		}
		m_curInBuf = m_buf;
		return true;
	}
	std::cout << "at the end of file or something wrong" << std::endl;
	return false;
}

std::string FileBuffer::nextElement()
{
	std::string tag(findTag());
	while(!tag.empty()) {
		std::cout << tag << std::endl;
		tag = findTag();
	}

	std::cout << std::endl;
	return "";
}

std::string FileBuffer::outputBuf()
{
	return m_buf;
}

int main (int argc, char const* argv[]) {
	std::ifstream wordFile(argv[1]);
	FileBuffer fileBuffer(wordFile);
	fileBuffer.nextElement();
	//while (fileBuffer.readMore()){
		//std::cout << fileBuffer.outputBuf() << std::endl;
	//}
	return 0;
}
