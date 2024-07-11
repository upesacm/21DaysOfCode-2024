import React, { useState } from 'react';

function TrafficLight() {
  // Initialize the state with the default color
  const [color, setColor] = useState('Red');

  // Function to handle button click
  const handleClick = () => {
    // Toggle through the traffic light colors
    switch (color) {
      case 'Red':
        setColor('Green');
        break;
      case 'Green':
        setColor('Yellow');
        break;
      case 'Yellow':
        setColor('Red');
        break;
      default:
        setColor('Red'); // Fallback in case of unexpected state
    }
  };

  return (
    <div>
      {/* Render the traffic light color */}
      <div style={{ backgroundColor: color }}>
        {color}
      </div>
      {/* Render the button to toggle the traffic light */}
      <button onClick={handleClick}>Toggle Light</button>
    </div>
  );
}

export default TrafficLight;