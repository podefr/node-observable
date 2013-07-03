Yet another fancy publish subscribe module, written in C++
-------------------------------------------------------------

```bash
npm install yapsl
```

```js
var yapsl = require("yapsl");

var observable = new yapsl.Observable;

observable.subscribe("topic", function (args) {
	console.log("arguments received", args);
}, this);

// It doesn't support more than one arg :(
observable.publish("topic", array);
```
