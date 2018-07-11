#include "parseName.h"

string parseName(string imgname)
{
	string s;
	for (int i = 0; i < imgname.length(); i++)
		if (imgname.at(i) == '.') {
			return imgname.substr(0, i) + ".kps";
			break;
		}
	return "";
}
