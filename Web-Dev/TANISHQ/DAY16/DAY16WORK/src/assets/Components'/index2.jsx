import React, { useState } from 'react';

const NameForm = () => {
  const [name, setName] = useState('');

  const handleSubmit = (event) => {
    event.preventDefault();
    alert(`Hello, ${name}!`);
  };

  const handleChange = (event) => {
    setName(event.target.value);
  };

  return (
    <form onSubmit={handleSubmit}>
      <label htmlFor="name">Name:</label>
      <input type="text" id="name" value={name} onChange={handleChange} />
      <button type="submit">Submit</button>
    </form>
  );
};

export default NameForm;