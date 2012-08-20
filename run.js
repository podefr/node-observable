var Observable = require("./build/Release/Observable").Observable,
	observable = new Observable;

observable.subscribe("hi", function() {
	console.log("hi called!", "!!");
});

observable.subscribe("coucou", function() {
	console.log("coucou called!", this, arguments, "!!");
});
observable.publish("coucou", ["lol"]);