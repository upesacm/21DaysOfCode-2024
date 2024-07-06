import React, { useState } from 'react';

const LikeButton = () => {
  const [likeCount, setLikeCount] = useState(0);

  const handleLike = () => {
    setLikeCount(likeCount + 1);
  };

  return (
    <div>
      <button onClick={handleLike}>Like</button>
      <span>{likeCount} likes</span>
    </div>
  );
};

export default LikeButton;
