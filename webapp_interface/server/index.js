const express = require("express");
const cors = require("cors");
const bodyParser = require("body-parser");

const expressApp = express();

// middle ware
expressApp.use(bodyParser.json());
expressApp.use(cors());

// routing api
const deviceDetails = require('./api/deviceDetails.js')
expressApp.use('/api/details',deviceDetails);

// toggling
const deviceToggle = require('./api/deviceToggle.js')
expressApp.use('/api/toggle',deviceToggle);

// any route go here
expressApp.get(/.*/, (request, response)=>{
    response.send("hey hey");
})

const port = 5000 || process.env.PORT;
expressApp.listen(5000, ()=>{console.log(`API started on port ${5000}`);} )