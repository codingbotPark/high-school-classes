import {
    useCallback,
    useRef,
  } from 'react';
  
  const useModal = (
    setter,
  ) => {
    // el이라는 곳에 e.target을 저장하게 된다
    const el = useRef(null);
  
    const clickOutside = useCallback(
      (e) => { // e.target을 확인한다
        if (el.current && !el.current.contains(e.target)) {
          setter(false);
        }
      },
      [setter],
    );
  
    return [el, clickOutside];
  };
  
  export default useModal;