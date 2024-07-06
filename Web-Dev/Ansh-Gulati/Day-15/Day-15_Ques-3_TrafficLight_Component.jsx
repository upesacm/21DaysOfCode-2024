import React, { useState } from 'react';
import './Day-15_Ques-3_TrafficLight_Component.css';

const TrafficLight = () => {
  const [light, setLight] = useState('Red');

  const handleClick = () => {
    setLight((prevLight) => {
      switch (prevLight) {
        case 'Red':
          return 'Green';
        case 'Green':
          return 'Yellow';
        case 'Yellow':
          return 'Red';
        default:
          return 'Red';
      }
    });
  };

  return (
    <div>
      <div className="traffic-light">
        <div className={`light ${light === 'Red' ? 'red' : ''}`}></div>
        <div className={`light ${light === 'Yellow' ? 'yellow' : ''}`}></div>
        <div className={`light ${light === 'Green' ? 'green' : ''}`}></div>
      </div>
      <button onClick={handleClick}>Change Light</button>
    </div>
  );
};

export default TrafficLight;
