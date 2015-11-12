var express = require('express');
var router = express.Router();
var mongoose = require('mongoose');

// our db model
var Sensor = require("../models/model.js");

/**
 * GET '/'
 * Default home route. Just relays a success message back.
 * @param  {Object} req
 * @return {Object} json
 */
router.get('/', function(req, res) {
  
  var jsonData = {
  	'name': 'node-express-api-arduino-yun',
  	'api-status':'OK'
  }

  // respond with json data
  res.json(jsonData)
});

router.post('/api/sensor/write', function(req,res){
    console.log(req.body);
    res.json(req.body);

    var sensorValue = req.body.
})




module.exports = router;