import axios from "axios";

// url change this when deployed
const url = 'http://localhost:5000/api/';

class DeviceService{
// -----------  device Details ------
    static getDevices(){    // GET all
        return new Promise(async (resolve, reject)=>{
            try {
                const res = await axios.get(`${url}details`);
                const data = res.data;
                resolve(
                    data.map(device=>({
                        ...device
                    }))
                ); 

            } catch (err) {
                reject(err);
            }
        });
    }

    // Device Details by Id
    static getDevice(id){   
        return new Promise(async (resolve, reject)=>{
            try {
                const res = await axios.get(`${url}details/${id}`);
                const data = res.data;
                
                resolve( data.map(device=>({ ...device })))
            } catch (err) { reject(err); }
        })
    }

    // top 4 reading for id
    static getLatest(id){
        return new Promise(async (resolve, reject)=>{
            try {
                const res =  await axios.get(`${url}details/${id}/latest`);
                const data = res.data;
                resolve(
                    data.map(readings=>({
                        ...readings
                    }))
                )
                
            } catch (error) {
                reject(error)
            }
        })
    }
    
    // check top results for b

    static check(){
        return axios.get(`${url}toggle/check`)
    }

    // set break code by id
    static break(id){
        return new Promise(async (resolve, reject)=>{
            try {
               const res = await axios.get(`${url}toggle/${id}/bad`); 
               const data = res.data;

               resolve(data.map( things =>({...things})))
            } catch (err) {
                reject(err);
            }
        })
    }
    
    // set by id pls
    static fix(id){
        return new Promise(async (resolve, reject)=>{
            try {
                const res = await axios.get(`${url}toggle/${id}/good`);
                const data = res.data;
                
                resolve(data.map(device=>({...device})))
            } catch (err) {
                reject(err);
            }
        })
        
    }
}


export default DeviceService;