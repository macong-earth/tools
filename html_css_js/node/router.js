function route(handle, pathname, response, request) {
  console.log("About to route a request for " + pathname);
  var cmd = pathname;
  if (pathname != "/") {
	  cmd = pathname.split("/")[1];
  }
  if (typeof handle[cmd] === 'function') {
    handle[cmd](response, request);
  } else {
    console.log("No request handler found for " + cmd);
    response.writeHead(404, {"Content-Type": "text/html"});
    response.write("404 Not found");
    response.end();
  }
}

exports.route = route;

