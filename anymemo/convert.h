#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

class Element
{
	public :
		enum Type {
			TAG,
			TEXT
		};
	public :
		Element(const std::string & content, Type type)
			: m_type(type), m_content(content)
		{
			if (TAG == m_type) {
				setAttrs();
			}
		}

		std::string string() const {return m_content;}
		Type type() const {return m_type;}
		void showAttrs() const;
	private:
		void setAttrs();
	private:
		Type m_type;
		std::string m_tagName;
		std::string m_content;
		std::map<std::string, std::string> m_attrs;
};

class FileBuffer
{
	public:
		FileBuffer(std::ifstream & file);
		~FileBuffer();

		Element nextElement();
		bool eof();
	private:
		char * findTagHead();
		char * getTagHead();
		char * getTagEnd();
		std::string getTag();

		std::string getText();

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
