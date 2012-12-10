function parseStr(str)
{
	var strArray = str.split("/");
	if (strArray[0]) {
		console.log(str + " ==> " + strArray[0]);
	}
}

parseStr("image/path/123.png");
parseStr("image/123.png");
parseStr("image");
parseStr("");
