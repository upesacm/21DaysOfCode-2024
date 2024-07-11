import React, { useState } from 'react';

function TrafficLight() {
  const [light, setLight] = useState('Red');

  const handleToggle = () => {
    switch (light) {
      case 'Red':
        setLight('Green');
        break;
      case 'Green':
        setLight('Yellow');
        break;
      case 'Yellow':
        setLight('Red');
        break;
      default:
        setLight('Red');
    }
  };

  return (
    <div style={{ textAlign: 'center', marginTop: '50px' }}>
      <div style={{ height: '150px', width: '50px', backgroundColor: '#333', margin: '0 auto', padding: '10px', borderRadius: '10px' }}>
        <div style={{ height: '40px', width: '40px', backgroundColor: light === 'Red' ? 'red' : '#555', margin: '10px auto', borderRadius: '50%' }}></div>
        <div style={{ height: '40px', width: '40px', backgroundColor: light === 'Yellow' ? 'yellow' : '#555', margin: '10px auto', borderRadius: '50%' }}></div>
        <div style={{ height: '40px', width: '40px', backgroundColor: light === 'Green' ? 'green' : '#555', margin: '10px auto', borderRadius: '50%' }}></div>
      </div>
      <button onClick={handleToggle} style={{ marginTop: '20px' }}>Toggle</button>
    </div>
  );
}

export default TrafficLight;
