var Observable = require("./build/Release/Observable").Observable,
	observable = new Observable;

var obj = {
	property: "hi"
};

observable.subscribe("topic1", function() {
	console.log("topic1 called");
});

observable.subscribe("topic1", function () {
	console.log("topic1 called with object", this, this.property);
}, obj);

observable.subscribe("notcalled", function () {

});

observable.publish("topic1");

