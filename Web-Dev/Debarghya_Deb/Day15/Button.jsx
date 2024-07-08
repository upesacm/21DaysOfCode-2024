import React from 'react'

function Button() {

    const[buttonName, setbuttonName] = React.useState("Click");
    
    
    const handleClick = () =>{
        setbuttonName("Clicked")
        
    }

  return (
    <div>

        <button className='change' onClick={handleClick} > {buttonName} </button>
    </div>
  )
}

export default Button