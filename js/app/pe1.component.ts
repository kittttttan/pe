import {Component} from 'angular2/core';
import {Pe1} from './pe/pe1';

@Component({
  selector: 'pe1',
  templateUrl: 'app/pe1.component.html'
})
export class Pe1Component {
  public n: number = 1000;
  public calc = Pe1.pe1;
}
