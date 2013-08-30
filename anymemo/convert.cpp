#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "convert.h"



FileBuffer::FileBuffer(std::ifstream & file) : m_bufLen(0),
	m_curInBuf(m_buf),
	m_file(file),
	m_isLastElementTag(false)
{
	m_buf[0] = 0;
}

FileBuffer::~FileBuffer()
{
	if(m_file) {
		m_file.close();
	}
}

std::string FileBuffer::trim(const std::string & tagStr)
{
	char lastCh = '\0';
	std::string str(tagStr);

	str.erase(std::remove_if(str.begin(), str.end(), [&lastCh](char ch){
				bool result = ::isspace(ch) && ::isspace(lastCh);
				lastCh = ch;
				return result;
				}), str.end());
	if (isspace(str.back())) {
		str.pop_back();
	}
	return str;
}

char* FileBuffer::findTagHead()
{
	char * pos = strchr(m_curInBuf, '<');
	if (pos) {
		m_curInBuf = pos;
	}
	return pos;
}


char* FileBuffer::getTagHead()
{
	char * pos = strchr(m_curInBuf, '<');
	if (pos) {
		m_curInBuf = pos + 1;
	}
	return pos;
}

char * FileBuffer::getTagEnd()
{
	char * pos = strchr(m_curInBuf, '>');
	if (pos) {
		m_curInBuf = pos + 1;
	}
	return pos;
}

std::string FileBuffer::getTag()
{
	std::string tag;

	char * tagHead = getTagHead();
	while(!tagHead && readMore()) {
		tagHead = getTagHead();
	}

	if (tagHead) {
		char * tagEnd = getTagEnd();
		if (tagEnd) {
			tag.append(tagHead, tagEnd + 1 - tagHead);
			return tag;
		} else {
			tag.append(tagHead);
		}

		while(readMore() && !(tagEnd = getTagEnd())) {
			tag.append(m_buf);
		}
		if (tagEnd) {
			tag.append(m_buf, tagEnd - m_buf + 1);
		}
	}

	return tag;
}

std::string FileBuffer::getText()
{
	std::string text;

	char * curPos = m_curInBuf;
	char * tagHead = findTagHead();
	if (tagHead) {
		text.append(curPos, tagHead - curPos);
		return text;
	} else {
		text.append(curPos);
	}

	while(readMore() && !(tagHead = findTagHead())) {
		text.append(m_buf);
	}
	if (tagHead) {
		text.append(m_buf, tagHead - m_buf);
	}

	return text;

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
	m_curInBuf = m_buf + m_bufLen;
	std::cout << "at the end of file or something wrong" << std::endl;
	return false;
}


Element FileBuffer::nextElement()
{
	std::string element;

	if (m_isLastElementTag) {
		element =  trim(getText());
		if (!element.empty()) {
			m_isLastElementTag = false;
			return Element(element, Element::TEXT);
		}
	}
	element =  trim(getTag());
	m_isLastElementTag = true;
	return Element(element, Element::TAG);

	//return Element(trim(getTag()), Element::TAG);
}

bool FileBuffer::eof()
{
	return !m_file && (m_curInBuf == (m_buf + m_bufLen));
}

int main (int argc, char const* argv[]) {
	std::ifstream wordFile(argv[1]);
	FileBuffer fileBuffer(wordFile);
	while (!fileBuffer.eof()) {
		Element element(fileBuffer.nextElement());
		if (element.type() == Element::TAG) {
			std::cout << element.string() << std::endl;
		}
	}
	return 0;
}

