import React from 'react';

const GreetUser = ({ username }) => {
  const greeting = username ? `Hello, ${username}!` : 'Hello, Guest!';
  return (
    <div>
      <h1>{greeting}</h1>
    </div>
  );
};

export default GreetUser;
