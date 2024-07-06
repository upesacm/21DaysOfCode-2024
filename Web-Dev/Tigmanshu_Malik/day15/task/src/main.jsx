import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App.jsx'
import './index.css'
import ButtonClicker from './ButtonClicker.jsx'
import LikeButton from './likeButton.jsx'
import TrafficLight from './trafficLight.jsx'

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <ButtonClicker />
    <LikeButton />
    <TrafficLight />
  </React.StrictMode>,
)
