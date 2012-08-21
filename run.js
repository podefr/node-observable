var Observable = require("./build/Release/Observable").Observable,
	observable = new Observable;

var obj = {
	property: "hi"
};

var func = function () {
	console.log("topic1 called with object", this, this.property);
};

observable.subscribe("topic1", function() {
	console.log("topic1 called");
});

observable.subscribe("topic1", func, obj);

observable.subscribe("notcalled", function () {

});

observable.publish("topic1");

console.log("hey", observable.hasObserver("topic1", func, obj));


