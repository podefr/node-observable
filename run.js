var Observable = require("./build/Release/Observable").Observable,
	observable = new Observable;

observable.subscribe("hello");
observable.subscribe("hi");
