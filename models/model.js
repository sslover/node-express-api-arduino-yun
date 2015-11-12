var mongoose = require('mongoose');
var Schema = mongoose.Schema;

// See http://mongoosejs.com/docs/schematypes.html

var sensorSchema = new Schema({
	value: String,
	dateAdded : { type: Date, default: Date.now },
})

// export 'Sensor' model so we can interact with it in other files
module.exports = mongoose.model('Sensor',sensorSchema);