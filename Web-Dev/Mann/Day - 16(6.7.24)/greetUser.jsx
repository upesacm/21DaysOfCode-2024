import React from 'react';
const GreetUser = ({username}) =>{
    return(
    <div>
      <h1>{username ? `Hello, ${username}!` : 'Hello, Guest!'}</h1>
    </div>
    )
}
export default GreetUser