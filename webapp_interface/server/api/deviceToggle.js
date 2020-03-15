const mongodb = require("mongodb").MongoClient;
const express = require("express");
const dbDetails = require("../../cred.js");

const toggler = express.Router();

// set good for device ID
toggler.get(`/:id/good`, async (req,resp)=>{
    const detail = await ConnectoDB();

    console.log(`fixing ${req.params.id}`);

    await detail.updateOne({_id:req.params.id},
    {
        $set:{ _rowVariant:'success', status:'OK'}
    });
    
     resp.send(await detail.find({_id:req.params.id}).toArray());
     
})

// Set bad for Device Id
toggler.get(`:id/bad`, async (req,resp)=>{
    const detail = await ConnectoDB();

    console.log(`breaking ${req.params.id}`);

    await detail.updateOne({_id:req.params.id},
    { 
        $set: { _rowVariant: 'danger', status:'BAD'}
    });
    
     resp.send(await detail.find({_id:req.params.id}).toArray());
})


// Main page Check -- safe, maybe add into details
toggler.get('/check', async (req, resp)=>{
    const sensor = await ConnectSensor();   // sensor collection
    const detail = await ConnectoDB();      // detail collection

    var limit = 4;
    var counter=0;          // under limit counter
    var status = 'good';    // base status
    var latest = await sensor.find({deviceId:'b'})    // get latest 4 collection
        .sort({timestamp: -1}).limit(limit).toArray();
    
    await latest.forEach((element) => {       // for each of the top5
        if(element.sensorReading < 130){ counter++; }   });
    
    if(counter === limit) {                 // update device > bad if counter === limit
        await detail.updateOne({_id:'b'}, {$set:{ _rowVariant: 'danger', status:'BAD'}});
        status = "bad";
    }
    resp.send(latest);
    console.log(status);  
})

// connect
async function ConnectoDB() {
    const client = await mongodb.connect(dbDetails.url, {useNewUrlParser:true});
    return client.db(dbDetails.dbName).collection(dbDetails.colDevice); // ready to do queries on connectDB()
}

async function ConnectSensor() {
    const client = await mongodb.connect(dbDetails.url, {useNewUrlParser:true});
    return client.db(dbDetails.dbName).collection(dbDetails.colSensorData); // ready to do queries on connectDB()
}

module.exports = toggler;