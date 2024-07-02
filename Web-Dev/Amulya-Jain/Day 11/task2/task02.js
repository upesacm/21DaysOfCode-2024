function runTwice(fun) {
    fun();
    fun();
}

document.getElementById('runTwiceBtn').onclick = function() {
  runTwice(function() {
      console.log('<Your_Name>');
  });
};
