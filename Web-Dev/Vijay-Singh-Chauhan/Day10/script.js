  // Question 1
  const button = document.querySelector('button').innerHTML;
  console.log(button);

// Question 2
  const btn2=document.querySelector('.btn2');
  btn2.textContent="hello!";


// Question 3
  document.getElementById('headbtn').addEventListener('click',function(){
      document.getElementById('result').textContent="You Choose: head";
  });
  document.getElementById('tailbtn').addEventListener('click',function(){
      document.getElementById('result').textContent="You Choose: tail";
  });

// Question 4 
  document.getElementById('smt-btn').addEventListener('click',function(){
      const name=document.getElementById('name-inpt').value;
      document.getElementById('result2').textContent=`Your name is: ${name}`;
  });

// Question 5

  document.getElementById('toggle').addEventListener('click',function(){
      const element=document.getElementById('toggleelement');
      if(element.style.display== 'none'){
          element.style.display= 'block';
      }
      else{
          element.style.display= 'none';
      }
  });
