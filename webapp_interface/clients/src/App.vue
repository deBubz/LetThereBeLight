<template>
  <div>
    <b-jumbotron bg-variant="dark" text-variant="white" id="nocurves">
      <template slot="header" header-level=4>
        <b-link :to="{ path: '/'}" id="nostyle">DarknessBgone</b-link>
      </template>
      <template slot="lead">
        <div>Lights are pretty cool</div>
      </template>
       <hr class="my-4" />
      <p>Gotta go fest and fix some lights</p>
    </b-jumbotron>

    <!-- MAIN CONTAINER -->
    <div id="giffspace"> <!--class="bv-example-row"-->
      <router-view></router-view>
    </div>
    <!-- MAIN CONTAINER ENDS -->

    <b-jumbotron bg-variant="dark" text-variant="white" id="nofooter">
      <template>
          End of the line
      </template>
    </b-jumbotron>
  </div>
</template>

<script>
</script>

<style>
#giffspace{
  margin-bottom: 0.1em;
  margin-top:0.1em;
}
#nocurves{
  border-radius: 0px;
  padding-bottom: 2em;
}
#nofooter{
  margin-bottom: 0;
  border-radius: 0px;
}
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}

#nostyle{
  text-decoration: none;
}
#nostyle:hover{
  text-decoration: none
}
</style>
