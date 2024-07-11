import React, { useState } from 'react';

const TrafficLight = () => {
  const [currentColor, setCurrentColor] = useState('red'); // Initial color

  const colors = ['red', 'yellow', 'green'];

  const handleClick = () => {
    const currentIndex = colors.indexOf(currentColor);
    const nextIndex = (currentIndex + 1) % colors.length; // Loop back to red

    setCurrentColor(colors[nextIndex]);
  };

  const lightStyle = {
    backgroundColor: currentColor,
    height: 100,
    width: 100,
    borderRadius: '50%',
    margin: '10px',
  };

  return (
    <div>
      <div style={lightStyle}></div>
      <button onClick={handleClick}>Toggle Light</button>
    </div>
  );
};

export default TrafficLight;
