#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

class Element
{
	public :
		enum Type {
			TAG,
			TEXT
		};
		enum TagType {
			OPENING_TAG,
			CLOSING_TAG
		};
	public :
		Element(const std::string & content, Type type)
			: m_type(type), m_content(content)
		{
			if (TAG == m_type) {
				setAttrs();
			}
		}

	public :
		std::string string() const {return m_content;}
		Type type() const {return m_type;}
		std::string tagName() const {return m_tagName;}
		TagType tagType() const {return m_tagType;}
		std::string attr(const std::string & attr) const;

		static bool isInFilter(const Element & tag);

		void showAttrs() const; //for test
	private:
		void setAttrs();
	private:
		Type m_type;
		TagType m_tagType;
		std::string m_tagName;
		std::string m_content;
		std::map<std::string, std::string> m_attrs;

		static const std::set<std::string> m_filter;
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


class TagStack
{
	public:
		TagStack() : m_wordTag(false), m_h4Tag(false), m_liTag(false) {}
		void add(Element tag);
		size_t getDepth() {return m_stack.size();};

	private:
		void pushProcess(Element tag);
		void popProcess(Element tag);
		std::vector<Element> m_stack;

	private:
		bool m_wordTag;
		bool m_h4Tag;
		bool m_liTag;
};
