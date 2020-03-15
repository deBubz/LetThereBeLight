<template>


  <b-container>
    <p> Heres a table</p>
    
    <div v-if="devices.length >0">
        <b-table hover :items="devices" :fields="fields">
          <template slot="place" slot-scope="data">
            {{data.item.location}}, {{data.item.post}}
          </template>

          <template slot="status">

          </template>

          <template slot="seemore" slot-scope="data">
            <b-link v-bind:href="'#/device/'+data.item._id">manage {{data.item._id}} </b-link>
            <!-- <b-link v-if="(data.item.status ==='OK')&&(data.item._id!='b')" 
            class="text-danger" v-on:click="kaboom(data.item._id)">|| Break it</b-link> -->
          </template>
        </b-table>
    </div>
    <div class="text-center m-5" v-else>
      <b-spinner/>
    </div>
  </b-container>

  
</template>

<script>
import DeviceService from '../DeviceService'


export default {
  name: 'Main',
  data(){
    return {
      fields: [
          { key: '_id', label: "Device Id"},
          { key: 'pid', label: 'PowerPole Id'},
          { key: 'place', label: 'Location'},
          { key: 'status', label: 'Light Status', sortable:true},
          { key: "seemore", label: ''}
        ],
      devices: [],
      breaking:[],
      error: "",
      interval: undefined
    }
  },

  methods: {
    async loadData(){
      await DeviceService.check();
      this.devices = await DeviceService.getDevices();
    },
    async kaboom(id){
      this.breaking = await DeviceService.break(id);
      // this.devices = await DeviceService.getDevices();
      alert(`what did you do to ${id}`);
      this.loadData();
    }
  },
  created(){
     this.loadData();
     this.interval = setInterval(this.loadData, 6000);
  
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
h3 {
  margin: 40px 0 0;
}
a {
  color: #42b983;
}
</style>
