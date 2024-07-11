
var d = new Date()
   


const hour = d.getHours();

if( 6<= hour <= 12 ){
    console.log("Good Morning")
}
else if ( 13<= hour <= 17 ){
    console.log("Good Afternoon!")

}
else{
    console.log("Good Night!")
}





function setAge(){

    let age =  document.getElementById('ageInput').value ;

    if(age < 6 || age > 65){
        console.log("Discount !")
    }
    else{
        console.log("No Discount.")
    }
     
}



const nums = [10,20,30]
nums[2] = 99

for (let index = 0; index <= 10; index = index + 2 ) {
    console.log(index);
    
}

for (let index = 5; index >= 0; index -- ) {
    console.log(index);
    
}