function runTwice(fun) {
    fun();
    fun();
}

runTwice(function() {
    console.log('Mradul');
});
