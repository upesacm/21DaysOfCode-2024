function runTwice(fun) {
    fun();
    fun();
}

document.getElementById('runBtn').onclick = function() {
  runTwice(function() {
      console.log('<Your_Name>');
  });
};
