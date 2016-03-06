import {Component} from 'angular2/core';
import {RouteConfig, ROUTER_DIRECTIVES} from 'angular2/router';

import {PeListComponent} from './pe-list.component';
import {Pe1Component} from './pe1.component';
import {Pe2Component} from './pe2.component';

@Component({
  selector: 'my-app',
  templateUrl: 'app/app.component.html',
  directives: [ROUTER_DIRECTIVES]
})
@RouteConfig([
  {path: '/pe-list', name: 'PeList', component: PeListComponent, useAsDefault: true},
  {path: '/pe1', name: 'Pe1', component: Pe1Component},
  {path: '/pe2', name: 'Pe2', component: Pe2Component},
])
export class AppComponent {
  public title: string = 'Solve Project Euler';
}
