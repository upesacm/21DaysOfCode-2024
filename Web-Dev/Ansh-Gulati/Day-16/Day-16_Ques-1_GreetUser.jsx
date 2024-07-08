import React from 'react';

const GreetUser = ({ username }) => {
  return (
    <div>
      {username ? (
        <h1>Hello, {username}!</h1>
      ) : (
        <h1>Hello, Guest!</h1>
      )}
    </div>
  );
};

export default GreetUser;
