import React, { useState } from 'react';

const InputLengthChecker = () => {
  const [input, setInput] = useState('');

  const message = input.length < 5 ? 'Too short' : 'Long enough';

  return (
    <div>
      <input
        type="text"
        value={input}
        onChange={(e) => setInput(e.target.value)}
      />
      <p>{message}</p>
    </div>
  );
};

export default InputLengthChecker;
