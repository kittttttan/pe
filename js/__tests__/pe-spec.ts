import {Pe1, Pe2, Pe3} from '../';

describe('Pe', ()=> {
  it('1', ()=> {
    expect(Pe1.solve()).toBe(234168);
    expect(Pe1.solveLoop()).toBe(234168);
  });

  it('2', ()=> {
    expect(Pe2.solve()).toBe(4613732);
  });

  it('3', ()=> {
    expect(Pe3.solve()).toStrictEqual([71, 839, 1471, 6857]);
  });
});
