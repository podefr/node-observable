var Observable = require("./build/Release/Observable").Observable,
	observable = new Observable;

// observable.subscribe("hi", function() {
// 	console.log("hi called!", "!!");
// });
var obj = {
	property: "hi"
};

observable.subscribe("coucou", function() {
	//console.log("coucou called!", this, arguments, "!!");
	console.log(this.property);
}, obj);


observable.publish("coucou");

