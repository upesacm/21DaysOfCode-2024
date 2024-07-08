import React from 'react'

function TrafficLight() {
    const TrafficLight = ["Red", "Green" , "Yellow" ]
    const [status, setStatus] = React.useState(0);

    const handleClick = () => {
        setStatus( (status+1) % 3 );
    }
    
return (
    <div>
         <button onClick={handleClick} >Change</button>
         <h3> {TrafficLight[status]} </h3>

    </div>
  )
}

export default TrafficLight