var url = require("url");

var querystring = require("querystring"),
    fs = require("fs"),
    formidable = require("formidable");

function start(response) {
  console.log("Request handler 'start' was called.");

  var body = '<html>'+
    '<head>'+
    '<meta http-equiv="Content-Type" '+
    'content="text/html; charset=UTF-8" />'+
    '</head>'+
    '<body>'+
	'"/upload" ==&gt; upload <br>' +
	'"/show/filename.png" ==&gt; download image. <br>' +
    '</body>'+
    '</html>';

    response.writeHead(200, {"Content-Type": "text/html"});
    response.write(body);
    response.end();
}

function upload(response, request) {
  console.log("Request handler 'upload' was called.");

  var form = new formidable.IncomingForm();
  console.log("about to parse");
  form.parse(request, function(error, fields, files) {
    console.log("parsing done");

    /* Possible error on Windows systems:
       tried to rename to an already existing file */
	var imgFileName = "/temp/" + files.image.name;
    fs.rename(files.image.path, imgFileName, function(err) {
      if (err) {
        fs.unlink(imgFileName);
        fs.rename(files.upload.path, imgFileName);
      }
    });
    response.writeHead(200, {"Content-Type": "text/html"});
    response.write("{\"image\" : {\"image\" : {\"originalUri\": \"/show/" + files.image.name + "\"}}}");
    response.end();
  });
}

function show(response, request) {
  console.log("Request handler 'show' was called.");
  var pathArray = url.parse(request.url).pathname.split("/");
  if (pathArray.length != 3 ) {
      response.writeHead(500, {"Content-Type": "text/plain"});
      response.end();
  }

  pathArray[1] = "temp";
  var imgFileName = pathArray.join("/");
  fs.readFile(imgFileName, "binary", function(error, file) {
    if(error) {
      response.writeHead(500, {"Content-Type": "text/plain"});
      response.write(error + "\n");
      response.end();
    } else {
      response.writeHead(200, {"Content-Type": "image/png"});
      response.write(file, "binary");
      response.end();
    }
  });
}

exports.start = start;
exports.upload = upload;
exports.show = show;

