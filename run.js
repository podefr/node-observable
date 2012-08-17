var Observable = require("./build/Release/Observable").Observable,
	observable = new Observable;

observable.subscribe("hello", function(args) {
	console.log("hello called!", this, args, "!!");
});
observable.publish("hellop");
