import React, { useState } from 'react';

const TrafficLight = () => {
  const [color, setColor] = useState('Red');

  const handleToggle = () => {
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
        setColor('Red');
    }
  };

  return (
    <div>
      <div
        style={{
          width: 100,
          height: 300,
          display: 'flex',
          flexDirection: 'column',
          justifyContent: 'space-between',
          alignItems: 'center',
        }}
      >
        <div
          style={{
            width: 50,
            height: 50,
            borderRadius: '50%',
            backgroundColor: color === 'Red' ? 'red' : 'gray',
          }}
        />
        <div
          style={{
            width: 50,
            height: 50,
            borderRadius: '50%',
            backgroundColor: color === 'Yellow' ? 'yellow' : 'gray',
          }}
        />
        <div
          style={{
            width: 50,
            height: 50,
            borderRadius: '50%',
            backgroundColor: color === 'Green' ? 'green' : 'gray',
          }}
        />
      </div>
      <button onClick={handleToggle}>Toggle Traffic Light</button>
    </div>
  );
};

export default TrafficLight;
