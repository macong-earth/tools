/**
 * \file generate definition page of specified words
 * \author Cong Ma
 * \date 2013-01-21
 */
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <map>
#include <vector>

using namespace std;

/**
 *  \brief infile css of GeneratePage.html
 */
extern string result_min_css;

/**
 * \brief type of div tag
 */
enum DivType {
	DIV_OPEN, /**< open div tag */
	DIV_CLOSE ///< close div tag
};

/** \brief find next div open or close tag in a html string
 *
 * @param htmlStr string to examine
 * @param pos position at which to begin searching
 * @return tuple<bool exist, size_t pos, DivType type>
 *    - exsit:
 *        + true if a div tag is found
 *        + false if no div tag is found
 *    - pos: position at which the tag starts
 *    - type: open or close div tag
 */
tuple<bool, size_t, DivType> getNextDivTag(const string & htmlStr, size_t pos)
{
	if (htmlStr.size() > pos) {
		for (size_t index = pos; index < htmlStr.size(); index++) {
			if (htmlStr[index] == '<') {
				if (strncmp(&htmlStr[index], "<div", 4) == 0) {
					return make_tuple(true, index, DIV_OPEN);
				} else if (strncmp(&htmlStr[index], "</div", 5) == 0) {
					return make_tuple(true, index, DIV_CLOSE);
				}
			}
		}
	}

	return make_tuple(false, 0, DIV_OPEN);
}

/** \brief cut div whose id is collinsResult from the html page
 * @param htmlStr html string at which to examine
 * @return null if there is no div with collinsResult as id
 */
string cutDiv(const string & htmlStr)
{
	string divStr;

	int divStackLevel = 1;
	size_t divStart = htmlStr.find("<div id=\"collinsResult\"");
	size_t currentPos = divStart;

	if (divStart != string::npos) {
		while(divStackLevel > 0) {
			auto nextDivTag = getNextDivTag(htmlStr, currentPos + 1);
			if (get<0>(nextDivTag)) {
				currentPos = get<1>(nextDivTag);
				get<2>(nextDivTag ) == DIV_OPEN ? divStackLevel++: divStackLevel--;
			} else {
				cout << "error happened." << endl;
				break;
			}
		}
	}

	if (divStackLevel <= 0) {
		size_t divEnd = currentPos + 6;
		divStr = htmlStr.substr(divStart, divEnd - divStart);
	}

	return divStr;
}

/**
 * \brief read content of a file to a string
 */
string readHtmlFile(const string & filename)
{
	string htmlStr;
	ifstream ifile(filename);
	if (ifile) {
		htmlStr.assign((istreambuf_iterator<char>(ifile)),
				(istreambuf_iterator<char>()));
	}
	ifile.close();

	return htmlStr;
}

string createPage(const map<string, string> & wordList)
{
	string htmlStr(string("\xEF\xBB\xBF<!DOCTYPE html>\n"
			"<html>\n"
			"<head>\n"
			"	<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n"
			"	<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n "
			"	<title>WORDS</title>\n"
			"	<style>\n")
			+ result_min_css +
			"	</style>\n"
			"</head>\n"
			"<body>\n"
			"<div id=\"sidebar\">\n"
			"[###SIDEBAR###]"
			"</div>\n"
			"<div id=\"main\">\n"
			"[###MAIN###]"
			"</div>\n"
			"<script>\n"
			"	var speaker = new Audio();\n"
			"	function pronounce(word) {\n"
			"		speaker.src = \"https://www.gstatic.com/dictionary/static/sounds/de/0/\" + word + \".mp3\";\n"
			"		speaker.play();\n"
			"}\n"
			"</script>\n"
			"</body>\n"
			"</html>\n"
			);

	string word;
	string sidebarStr;
	string mainStr;

	for(auto it = wordList.begin(); it != wordList.end(); ++it) {
		sidebarStr += "<h3><a href=\"#word-" + it->first + "\" onclick=\"pronounce('" + it->first + "')\">" + it->first + "</a></h3>\n";
		mainStr += "<div id=\"word-" + it->first + "\"\n>" + it->second + "</div>\n";
	}

	htmlStr.replace(htmlStr.find("[###SIDEBAR###]"), 15, sidebarStr);
	htmlStr.replace(htmlStr.find("[###MAIN###]"), 12, mainStr);
	return htmlStr;
}

int main (int argc, char const* argv[]) {
	if (argc < 2) {
		return EXIT_FAILURE;
	}

	map<string, string> wordList;

	for (int i = 1; i < argc; i++) {
		string word(argv[i]);

		string htmlStr = readHtmlFile(word + ".html");
		string divStr  = cutDiv(htmlStr);

		if (!divStr.empty()) {
			wordList[word] = divStr;
		}
	}

	string pageStr(createPage(wordList));
	cout << pageStr << endl;
	return EXIT_SUCCESS;
}

