<template>
  <b-container id="somespace">
    <div  v-if="deviceData.length >0">
      <h2 align-item-center>Detailed view</h2> <!--could chuck this in a component-->
      <b-row  v-for="(device, index) in deviceData" v-bind:item="device" v-bind:index="index" v-bind:key="device._id">
        <b-col>
          <b-card title="Details" class="text-primary" style="max-width: 20rem;">
            <b-card-text>Light Status: 
              <span v-if="device.status === 'BAD'" class="text-danger ">{{device.status}}</span> 
              <span v-else class="text-success">{{device.status}}</span>
            </b-card-text>
            <b-card-text>Device Id: <span class="text-dark">{{device._id}}</span></b-card-text>
            <b-card-text>UtilityPole Id: <span class="text-dark">{{device.pid}}</span></b-card-text>
            <b-card-text>Locatin: <span class="text-dark">{{device.location}}</span></b-card-text>
            <b-card-text>PostCode: <span class="text-dark">{{device.post}}</span></b-card-text>
            <b-button v-if="device.status === 'BAD'"  class="bg-danger text-white"
            v-on:click="ifixit"
            >Add to Repair Queue</b-button>
            </b-card>
        
        </b-col>
    
    
        <b-col>
          <LiveData />
        </b-col>
      </b-row>
    </div>
    <div class="text-center m-5" v-else>
      <b-spinner/>
    </div>

  </b-container>  <!--CONTEINER START-->
</template>

<script>
import DeviceService from '../DeviceService'
import LiveData from '../components/liveData'


export default {
  name: 'Details',
  components:{
    LiveData
  },
   data(){
     return{
       deviceData:[],
       error: "",
       interval: undefined
     }
    },
    async created(){
      this.loadData();
      this.interval = setInterval(this.loadData,4000)
    },
    methods: {
      async ifixit() {
        try {
          alert("hey there")
          this.deviceData = await DeviceService.fix(this.$route.params.id);
          alert('Ithink its fixed')
        } catch (err) {
          this.error =err.message
        }
      },
      async loadData(){
        // await DeviceService.check();
        this.deviceData = await DeviceService.getDevice(this.$route.params.id);
      }
    },
    beforeDestroy() {
    // if (this.interval) {
      clearInterval(this.interval)
      this.interval = undefined
    // }
  }  
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
#somespace{
  margin-bottom:0.2rem;
}
h3 {
  margin: 40px 0 0;
}
a {
  color: #42b983;
}
.container{
  min-height: 200px;
}
</style>
