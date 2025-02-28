export default function GhBadge(props: { name: string; className?: string }) {
  const { name, className } = props;

  return (
    <a
      className={`${className} inline-flex items-center gap-1 hover:opacity-80`}
      href={`https://github.com/${name}`}
      target="_blank"
      rel="noreferrer"
    >
      <img
        className="avatar h-[1.2em] rounded-full"
        src={`https://wsrv.nl/?url=github.com/${name}.png%3fsize=48`}
        alt=""
      />
      {name}
    </a>
  );
}
