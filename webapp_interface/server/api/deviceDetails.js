const mongodb = require("mongodb").MongoClient;
const express = require("express");
const dbDetails = require("../../cred.js");

const router = express.Router();

// GET  all devices
router.get("/", async(req, resp)=>{
    const detail = await ConnectoDB();
    resp.send(await detail.find({}).toArray()); // send json as a response
})

//
// GET details by id
router.get(`/:id`, async(req, resp)=>{
    const detail = await ConnectoDB();
    resp.send(await detail.find({_id:req.params.id}).toArray());
})

// get latest list of data
router.get(`/:id/latest`, async (req, resp)=>{
    const listSize = 4;
    const sensor = await ConnectSensor();
    resp.send(await sensor.find({deviceId:req.params.id}).sort({timestamp: -1}).limit(listSize).toArray());
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

module.exports = router;