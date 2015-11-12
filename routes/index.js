var express = require('express');
var router = express.Router();
var mongoose = require('mongoose');

// our db model
var Temperature = require("../models/model.js");

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
    
    var currentTemp = req.body.temperature;
    // can now save to DB
    var temperature = new Temperature({value:currentTemp})

    temperature.save(function(err,data){
    	if(err){
    		res.json({status:'error',message: err})
    	}
    	res.json(data);
    })

})

router.get('/api/get/latest',function(req,res){

  Temperature.find().sort('-dateAdded').exec(function(err,data){
    if(err){
      var error = {
        status: "ERROR",
        message: err
      }
      res.json(error);      
    }
    else {
      var jsonData = {
        status: "OK",
        status: data[0]
      }
      res.send(data[0].value);   
    }    
  })

})




module.exports = router;