require("babel-register")({
	presets: ["es2015"],
	plugins: ["transform-decorators-legacy"]
});

require("./decorator");
