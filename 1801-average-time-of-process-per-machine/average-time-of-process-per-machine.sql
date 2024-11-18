select u.machine_id,Round(sum(v.timestamp-u.timestamp)/count(*),3) as processing_time from Activity as u Join Activity as v on (u.machine_id=v.machine_id and u.process_id=v.process_id and u.activity_type="start" and v.activity_type="end") group by u.machine_id;