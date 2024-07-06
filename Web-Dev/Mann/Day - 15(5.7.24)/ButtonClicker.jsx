import React, { useState } from 'react';

const ButtonClicker = () => {
  const [buttonText, setButtonText] = useState('Click Me!');

  const handleClick = () => {
    setButtonText('Clicked');
  };

  return (
    <button onClick={handleClick} className="btn">
      {buttonText}
    </button>
  );
};

export default ButtonClicker;