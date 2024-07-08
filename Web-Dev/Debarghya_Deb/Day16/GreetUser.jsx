import React from 'react'

function GreetUser(props) {
  return (
    
    
    
    <div>
        {props.username ? <h1>Welcome, {props.username}!</h1> : <h1>Welcome, guest!</h1>}
         
    </div>
  )
}

export default GreetUser