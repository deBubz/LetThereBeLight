

<template>
    <div class="text-center"> <!-- main cointainer-->
        <h1> Data</h1>
        <div v-for="(reading, index) in Readings " v-bind:item="reading" v-bind:index="index" v-bind:key="reading._id">
            <h1 v-if="(index ===0)&&reading.sensorReading<120"><b-badge variant="danger">{{reading.sensorReading}}</b-badge></h1>
            <h1 v-else-if="(index ===0)"><b-badge variant="success">{{reading.sensorReading}}</b-badge></h1>
            <p v-else>{{reading.sensorReading}}</p>
            
        </div>
    </div> <!-- main container ends-->
</template>

<script>
import DeviceService from '../DeviceService'

export default {
    name: 'LiveData',
    data(){
        return{
            Readings: [],
            interval: undefined,
            error: ""
        }
    },
    methods: {
        async loadData(){
            this.Readings = await DeviceService.getLatest(this.$route.params.id);
        }
    },
    created() {
        this.loadData();
        this.interval = setInterval(this.loadData, 1000);
    },
      beforeDestroy() {
    if (this.interval) {
      clearInterval(this.interval)
      this.interval = undefined
    }
      }
}
</script>
