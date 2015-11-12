var mongoose = require('mongoose');
var Schema = mongoose.Schema;

// See http://mongoosejs.com/docs/schematypes.html

var temperatureSchema = new Schema({
	value: String,
	dateAdded : { type: Date, default: Date.now },
})

// export 'Temperature' model so we can interact with it in other files
module.exports = mongoose.model('Temperature',temperatureSchema);