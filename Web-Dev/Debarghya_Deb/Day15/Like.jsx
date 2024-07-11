import React from 'react'

function Like() {
  
    const [likeCount, setLikeCount] = React.useState(0)
    
   const handleClick = () => {
        setLikeCount(likeCount+1);
    }
  
    return (
    <div>
        <button className='Like' onClick={handleClick} >Like</button>
        <br />
        <h4>{likeCount} </h4>
    </div>
  )
}

export default Like