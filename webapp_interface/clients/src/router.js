import Vue from 'vue'
import Router from 'vue-router'
import Main from './views/Main.vue'
import DeviceP from './views/DeviceP.vue'


Vue.use(Router);

export default new Router({
    routes:[
        {
            path: '/',
            name: 'main',
            component: Main
        },
        {
            path: '/device/:id',
            name: 'device',
            component: DeviceP
        }
    ]
})